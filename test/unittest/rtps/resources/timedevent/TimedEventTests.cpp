// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "mock/MockEvent.h"
#include <fastrtps/rtps/resources/ResourceEvent.h>
#include <thread>
#include <random>
#include <gtest/gtest.h>

class TimedEventEnvironment : public ::testing::Environment
{
    public:

        void SetUp()
        {
            service_.init_thread();
        }

        void TearDown()
        {
        }

        eprosima::fastrtps::rtps::ResourceEvent service_;
};

TimedEventEnvironment* const env = dynamic_cast<TimedEventEnvironment*>(testing::AddGlobalTestEnvironment(new TimedEventEnvironment));

/*!
 * @fn TEST(TimedEvent, Event_SuccessEvents)
 * @brief This test checks the correct behavior of launching events.
 * This test launches an event several times.
 * For each one it waits its execution and then launches it again.
 */
TEST(TimedEvent, Event_SuccessEvents)
{
    MockEvent event(env->service_, 100, false);

    for(int i = 0; i < 10; ++i)
    {
        event.event().restart_timer();
        event.wait();
    }

    int successed = event.successed_.load(std::memory_order_relaxed);

    ASSERT_EQ(successed, 10);

    int cancelled = event.cancelled_.load(std::memory_order_relaxed);

    ASSERT_EQ(cancelled, 0);
}

/*!
 * @fn TEST(TimedEvent, Event_CancelEvents)
 * @brief This test  checks the correct behavior of cancelling events.
 * This test launches an event several times and cancels it.
 * For each one it launchs the event and inmediatly it cancels the event.
 * Then it waits until the cancelation is executed.
 */
TEST(TimedEvent, Event_CancelEvents)
{
    MockEvent event(env->service_, 100, false);

    for(int i = 0; i < 10; ++i)
    {
        event.event().restart_timer();
        event.event().cancel_timer();
        event.wait();
    }

    int successed = event.successed_.load(std::memory_order_relaxed);

    ASSERT_EQ(successed, 0);

    int cancelled = event.cancelled_.load(std::memory_order_relaxed);

    ASSERT_EQ(cancelled, 10);
}

/*!
 * @fn TEST(TimedEvent, Event_RestartEvents)
 * @brief This test checks the correct behaviour of restarting events.
 * This test restart continuisly several events.
 */
TEST(TimedEvent, Event_RestartEvents)
{
    MockEvent event(env->service_, 100, false);

    for(int i = 0; i < 10; ++i)
    {
        event.event().cancel_timer();
        event.event().restart_timer();
    }

    for(int i = 0; i < 10; ++i)
    {
        event.wait();
    }

    int successed = event.successed_.load(std::memory_order_relaxed);

    ASSERT_EQ(successed, 1);

    int cancelled = event.cancelled_.load(std::memory_order_relaxed);

    ASSERT_EQ(cancelled, 9);
}


/*!
 * @fn TEST(TimedEvent, Event_AutoRestart)
 * @brief This test checks an event is able to restart itself.
 * This test launches an event several times and this event also restarts itself.
 */
TEST(TimedEvent, Event_AutoRestart)
{
    MockEvent event(env->service_, 10 , true);

    for(unsigned int i = 0; i < 100; ++i)
    {
        event.event().restart_timer();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    int successed = event.successed_.load(std::memory_order_relaxed);

    ASSERT_GE(successed , 100);
}


/*!
 * @fn TEST(TimedEvent, Event_AutoRestartAndDeleteRandomly)
 * This test checks an event, configured to restart itself, can be deleted while
 * it is being scheduled.
 * This test launches an event that restarts itself, and then randomly deletes it.
 */
TEST(TimedEvent, Event_AutoRestartAndDeleteRandomly)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 100);

    MockEvent event(env->service_, 2, true);

    event.event().restart_timer();
    std::this_thread::sleep_for(std::chrono::milliseconds(dis(gen)));
}

/*!
 * @brief Auxyliary function to be run in multithread tests.
 * It restarts an event in a loop.
 * @param Event to be restarted.
 * @param num_loop Number of loops.
 * @param sleep_time Sleeping time between each loop.
 */
void restart(MockEvent *event, unsigned int num_loop, unsigned int sleep_time)
{
    for(unsigned int i = 0; i < num_loop; ++i)
    {
        event->event().restart_timer();

        if(sleep_time > 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
    }
}

/*!
 * @brief Auxyliary function to be run in multithread tests.
 * It cancels an event in a loop.
 * @param Event to be restarted.
 * @param num_loop Number of loops.
 * @param sleep_time Sleeping time between each loop.
 */
void cancel(MockEvent *event, unsigned int num_loop, unsigned int sleep_time)
{
    for(unsigned int i = 0; i < num_loop; ++i)
    {
        event->event().cancel_timer();

        if(sleep_time > 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
    }
}

/*!
 * @fn TEST(TimedEventMultithread, EventNonAutoDestruc_TwoStartTwoCancel)
 * @brief This function checks multithreading usage of events.
 * This function launches four threads. Two threads restart the event, and the other two
 * cancel it.
 */
TEST(TimedEventMultithread, Event_TwoStartTwoCancel)
{
    std::thread *thr1 = nullptr, *thr2 = nullptr,
        *thr3 = nullptr, *thr4 = nullptr;

    MockEvent event(env->service_, 3, false);

    // 2 Thread restarting and two thread cancel.
    // Thread 1 -> Restart 100 times waiting 100ms between each one.
    // Thread 2 -> Cancel 100 times waiting 102ms between each one.
    // Thread 3 -> Restart 80 times waiting 110ms between each one.
    // Thread 4 -> Cancel 80 times waiting 112ms between each one.

    thr1 = new std::thread(restart, &event, 100, 100);
    thr2 = new std::thread(cancel, &event, 100, 102);
    thr3 = new std::thread(restart, &event, 80, 110);
    thr4 = new std::thread(cancel, &event, 80, 112);

    thr1->join();
    thr2->join();
    thr3->join();
    thr4->join();

    delete thr1;
    delete thr2;
    delete thr3;
    delete thr4;

    // Wait until finish the execution of the event.
    int count = 0;
    while(event.wait(500))
    {
        ++count;
    }

    int successed = event.successed_.load(std::memory_order_relaxed);
    int cancelled = event.cancelled_.load(std::memory_order_relaxed);

    ASSERT_EQ(successed + cancelled, count);
}

/*!
 * @fn TEST(TimedEventMultithread, EventNonAutoDestruc_FourAutoRestart)
 * @brief This function checks an event, configured to restart itself, is able to
 * be restarted in several threads.
 * This function launches four threads and each one restart the event.
 */
TEST(TimedEventMultithread, Event_FourAutoRestart)
{
    std::thread *thr1 = nullptr, *thr2 = nullptr,
        *thr3 = nullptr, *thr4 = nullptr;

    MockEvent event(env->service_, 2, true);

    // 2 Thread restarting and two thread cancel.
    // Thread 1 -> AutoRestart 100 times waiting 2ms between each one.
    // Thread 2 -> AutoRestart 100 times waiting 3ms between each one.
    // Thread 3 -> AutoRestart 80 times waiting 4ms between each one.
    // Thread 4 -> AutoRestart 80 times waiting 5ms between each one.

    thr1 = new std::thread(restart, &event, 100, 2);
    thr2 = new std::thread(restart, &event, 100, 3);
    thr3 = new std::thread(restart, &event, 80, 4);
    thr4 = new std::thread(restart, &event, 80, 5);

    thr1->join();
    thr2->join();
    thr3->join();
    thr4->join();

    delete thr1;
    delete thr2;
    delete thr3;
    delete thr4;

    // Wait a prudential time before delete the event.
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
