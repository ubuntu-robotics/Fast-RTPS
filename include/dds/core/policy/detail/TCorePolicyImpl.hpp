/*
 * Copyright 2019, Proyectos y Sistemas de Mantenimiento SL (eProsima).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef EPROSIMA_DDS_CORE_POLICY_TCOREPOLICY_IMPL_HPP_
#define EPROSIMA_DDS_CORE_POLICY_TCOREPOLICY_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/policy/CorePolicy.hpp>
//TODO: Fix when ReportUtils is implemented
//#include <org/opensplice/core/ReportUtils.hpp>

namespace dds {
namespace core {
namespace policy {

//TUserData

template<typename D>
TUserData<D>::TUserData() : dds::core::Value<D>() { }

template<typename D>
TUserData<D>::TUserData(
        const dds::core::ByteSeq& sequence)
    : dds::core::Value<D>(sequence) { }

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
TUserData<D>::TUserData(
        const uint8_t* value_begin,
        const uint8_t* value_end)
{
    //To implement
}

template<typename D>
TUserData<D>::TUserData(
        const TUserData& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TUserData<D>& TUserData<D>::value(
        const dds::core::ByteSeq& sequence)
{
    //To implement
}

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
template<typename OCTET_ITER>
TUserData<D>& TUserData<D>::value(
        OCTET_ITER begin,
        OCTET_ITER end)
{
    //To implement
}

template<typename D>
const dds::core::ByteSeq TUserData<D>::value() const
{
    //To implement
}

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
const uint8_t* TUserData<D>::begin() const
{
    //To implement
}

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
const uint8_t* TUserData<D>::end() const
{
    //To implement
}

//TGroupData

template<typename D>
TGroupData<D>::TGroupData() : dds::core::Value<D>() { }

template<typename D>
TGroupData<D>::TGroupData(
        const dds::core::ByteSeq& sequence)
    : dds::core::Value<D>(sequence) { }

template<typename D>
TGroupData<D>::TGroupData(
        const TGroupData& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TGroupData<D>::TGroupData(
        const uint8_t* value_begin,
        const uint8_t* value_end)
{
    //To implement
}

template<typename D>
TGroupData<D>& TGroupData<D>::value(
        const dds::core::ByteSeq& sequence)
{
    //To implement
}

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
template<typename OCTET_ITER>
TGroupData<D>& TGroupData<D>::value(
        OCTET_ITER begin,
        OCTET_ITER end)
{
    //To implement
}

template<typename D>
const dds::core::ByteSeq TGroupData<D>::value() const
{
    //To implement
}

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
const uint8_t* TGroupData<D>::begin() const
{
    //To implement
}

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
const uint8_t* TGroupData<D>::end() const
{
    //To implement
}

//TTopicData

template<typename D>
TTopicData<D>::TTopicData() : dds::core::Value<D>() { }

template<typename D>
TTopicData<D>::TTopicData(
        const dds::core::ByteSeq& sequence)
    : dds::core::Value<D>(sequence) { }

template<typename D>
TTopicData<D>::TTopicData(
        const TTopicData& other)
    : dds::core::Value<D>(other.delegate()) { }

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
TTopicData<D>::TTopicData(
        const uint8_t* value_begin,
        const uint8_t* value_end)
{
    //To implement
}

template<typename D>
TTopicData<D>& TTopicData<D>::value(
        const dds::core::ByteSeq& sequence)
{
    //To implement
}

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
template<typename OCTET_ITER>
TTopicData<D>& TTopicData<D>::value(
        OCTET_ITER begin,
        OCTET_ITER end)
{
    //To implement
}

template<typename D>
const dds::core::ByteSeq TTopicData<D>::value() const
{
    //To implement
}

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
const uint8_t* TTopicData<D>::begin() const
{
    //To implement
}

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
const uint8_t* TTopicData<D>::end() const
{
    //To implement
}

//TEntityFactory

template<typename D>
TEntityFactory<D>::TEntityFactory(
        bool autoenable_created_entities)
    : dds::core::Value<D>(autoenable_created_entities) { }

template<typename D>
TEntityFactory<D>::TEntityFactory(
        const TEntityFactory& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TEntityFactory<D>& TEntityFactory<D>::autoenable_created_entities(
        bool autoenable_created_entities)
{
    //To implement
}

template<typename D>
bool TEntityFactory<D>::autoenable_created_entities() const
{
    //To implement
}

template<typename D>
TEntityFactory<D> TEntityFactory<D>::AutoEnable()
{
    //To implement
}

template<typename D>
TEntityFactory<D> TEntityFactory<D>::ManuallyEnable()
{
    //To implement
}

//TTransportPriority

template <typename D>
TTransportPriority<D>::TTransportPriority(
        int32_t priority)
    : dds::core::Value<D>(priority) { }

template<typename D>
TTransportPriority<D>::TTransportPriority(
        const TTransportPriority& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TTransportPriority<D>& TTransportPriority<D>::value(
        int32_t priority)
{
    //To implement
}

template<typename D>
int32_t TTransportPriority<D>::value() const
{
    //To implement
}

//TLifeSpan

template<typename D>
TLifespan<D>::TLifespan(
        const dds::core::Duration& duration)
    : dds::core::Value<D>(duration) { }

template<typename D>
TLifespan<D>::TLifespan(
        const TLifespan& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TLifespan<D>& TLifespan<D>::duration(
        const dds::core::Duration& duration)
{
    //To implement
}

template<typename D>
const dds::core::Duration TLifespan<D>::duration() const
{
    //To implement
}

//TDeadline

template<typename D>
TDeadline<D>::TDeadline(
        const dds::core::Duration& period)
    : dds::core::Value<D>(period) { }

template<typename D>
TDeadline<D>::TDeadline(
        const TDeadline& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TDeadline<D>& TDeadline<D>::period(
        const dds::core::Duration& period)
{
    //To implement
}

template<typename D>
const dds::core::Duration TDeadline<D>::period() const
{
    //To implement
}

//TLatencyBudget

template<typename D>
TLatencyBudget<D>::TLatencyBudget(
        const dds::core::Duration& duration)
    : dds::core::Value<D>(duration) { }

template<typename D>
TLatencyBudget<D>::TLatencyBudget(
        const TLatencyBudget& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TLatencyBudget<D>& TLatencyBudget<D>::duration(
        const dds::core::Duration& duration)
{
    //To implement
}

template<typename D>
const dds::core::Duration TLatencyBudget<D>::duration() const
{
    //To implement
}

//TTimeBasedFilter
template<typename D>
TTimeBasedFilter<D>::TTimeBasedFilter(
        const dds::core::Duration& minimum_separation)
    : dds::core::Value<D>(minimum_separation) { }

template<typename D>
TTimeBasedFilter<D>::TTimeBasedFilter(
        const TTimeBasedFilter& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TTimeBasedFilter<D>& TTimeBasedFilter<D>::minimum_separation(
        const dds::core::Duration& minimum_separation)
{
    //To implement
}

template<typename D>
const dds::core::Duration TTimeBasedFilter<D>::minimum_separation() const
{
    //To implement
}

//TPartition

template<typename D>
TPartition<D>::TPartition(
        const std::string& name)
    : dds::core::Value<D>(name)
{

}

template<typename D>
TPartition<D>::TPartition(
        const dds::core::StringSeq& names)
    : dds::core::Value<D>(names)
{

}

template<typename D>
TPartition<D>::TPartition(
        const TPartition& other)
    : dds::core::Value<D>(other.delegate())
{

}

template<typename D>
TPartition<D>& TPartition<D>::name(
        const std::string& name)
{
    //To implement
}

template<typename D>
TPartition<D>& TPartition<D>::name(
        const dds::core::StringSeq& names)
{
    //To implement
}

template<typename D>
const dds::core::StringSeq TPartition<D>::name() const
{
    //To implement
}

#ifdef OMG_DDS_OWNERSHIP_SUPPORT

//TOwnership

template<typename D>
TOwnership<D>::TOwnership(
        dds::core::policy::OwnershipKind::Type kind)
    : dds::core::Value<D>(kind) { }

template<typename D>
TOwnership<D>::TOwnership(
        const TOwnership& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TOwnership<D>& TOwnership<D>::kind(
        dds::core::policy::OwnershipKind::Type kind)
{
    //To implement
}

template<typename D>
dds::core::policy::OwnershipKind::Type TOwnership<D>::kind() const
{
    //To implement
}

template<typename D>
TOwnership<D> TOwnership<D>::Exclusive()
{
    //To implement
}

template<typename D>
TOwnership<D> TOwnership<D>::Shared()
{
    //To implement
}

//TOwnershipStrength
template<typename D>
TOwnershipStrength<D>::TOwnershipStrength(
        int32_t strength)
    : dds::core::Value<D>(strength) { }

template<typename D>
TOwnershipStrength<D>::TOwnershipStrength(
        const TOwnershipStrength& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
int32_t TOwnershipStrength<D>::value() const
{
    //To implement

template<typename D>
TOwnershipStrength<D>& TOwnershipStrength<D>::value(
            int32_t strength)
{
    //To implement
}

#endif  //OMG_DDS_OWNERSHIP_SUPPORT

//TWriterDataLifeCycle
template typename D>
TWriterDataLifecycle<D>::TWriterDataLifecycle(
            bool autodispose_unregistered_instances)
    : dds::core::Value<D>(autodispose_unregistered_instances) { }

template<typename D>
TWriterDataLifecycle<D>::TWriterDataLifecycle(
            const TWriterDataLifecycle& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
bool TWriterDataLifecycle<D>::autodispose_unregistered_instances() const
{
    //To implement
}

template<typename D>
TWriterDataLifecycle<D>& TWriterDataLifecycle<D>::autodispose_unregistered_instances(
            bool autodispose_unregistered_instances)
{
    //To implement
}

template<typename D>
TWriterDataLifecycle<D> TWriterDataLifecycle<D>::AutoDisposeUnregisteredInstances()
{
    //To implement
}

template<typename D>
TWriterDataLifecycle<D> TWriterDataLifecycle<D>::ManuallyDisposeUnregisteredInstances()
{
    //To implement
}

//TReaderDataLifecycle
template<typename D>
TReaderDataLifecycle<D>::TReaderDataLifecycle(
            const dds::core::Duration& autopurge_nowriter_samples_delay,
            const dds::core::Duration& autopurge_disposed_samples_delay)
    : dds::core::Value<D>(autopurge_nowriter_samples_delay, autopurge_disposed_samples_delay) { }

template<typename D>
TReaderDataLifecycle<D>::TReaderDataLifecycle(
            const TReaderDataLifecycle& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
const dds::core::Duration TReaderDataLifecycle<D>::autopurge_nowriter_samples_delay() const
{
    //To implement
}

template<typename D>
TReaderDataLifecycle<D>& TReaderDataLifecycle<D>::autopurge_nowriter_samples_delay(
            const dds::core::Duration& autopurge_nowriter_samples_delay)
{
    //To implement
}

template<typename D>
const dds::core::Duration TReaderDataLifecycle<D>::autopurge_disposed_samples_delay() const
{
    //To implement
}

template<typename D>
TReaderDataLifecycle<D>& TReaderDataLifecycle<D>::autopurge_disposed_samples_delay(
            const dds::core::Duration& autopurge_disposed_samples_delay)
{
    //To implement
}

template<typename D>
TReaderDataLifecycle<D> TReaderDataLifecycle<D>::NoAutoPurgeDisposedSamples()
{
    //To implement
}

template<typename D>
TReaderDataLifecycle<D> TReaderDataLifecycle<D>::AutoPurgeDisposedSamples(
            const dds::core::Duration& autopurge_disposed_samples_delay)
{
    //To implement
}

//TDurability

template<typename D>
TDurability<D>::TDurability(
            dds::core::policy::DurabilityKind::Type kind)
    : dds::core::Value<D>(kind) { }

template<typename D>
TDurability<D>::TDurability(
            const TDurability& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TDurability<D>& TDurability<D>::kind(
            dds::core::policy::DurabilityKind::Type kind)
{
    //To implement
}

template<typename D>
dds::core::policy::DurabilityKind::Type TDurability<D>::kind() const
{
    //To implement
}

template<typename D>
TDurability<D> TDurability<D>::Volatile()
{
    //To implement
}

template<typename D>
TDurability<D> TDurability<D>::TransientLocal()
{
    //To implement
}

template<typename D>
TDurability<D> TDurability<D>::Transient()
{
    //To implement
}

template<typename D>
TDurability<D> TDurability<D>::Persistent()
{
    //To implement
}

//TPresentation
template<typename D>
TPresentation<D>::TPresentation(
            dds::core::policy::PresentationAccessScopeKind::Type access_scope,
            bool coherent_access,
            bool ordered_access)
    : dds::core::Value<D>(access_scope, coherent_access, ordered_access) { }

template<typename D>
TPresentation<D>::TPresentation(
            const TPresentation& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TPresentation<D>& TPresentation<D>::access_scope(
            dds::core::policy::PresentationAccessScopeKind::Type access_scope)
{
    //To implement
}

template<typename D>
dds::core::policy::PresentationAccessScopeKind::Type TPresentation<D>::access_scope() const
{
    //To implement
}

template<typename D>
TPresentation<D>& TPresentation<D>::coherent_access(
            bool coherent_access)
{
    //To implement
}

template<typename D>
bool TPresentation<D>::coherent_access() const
{
    //To implement
}

template<typename D>
TPresentation<D>& TPresentation<D>::ordered_access(
            bool ordered_access)
{
    //To implement
}

template<typename D>
bool TPresentation<D>::ordered_access() const
{
    //To implement
}

template<typename D>
TPresentation<D> TPresentation<D>::GroupAccessScope(
            bool coherent_access,
            bool ordered_access)
{
    //To implement
}

template<typename D>
TPresentation<D> TPresentation<D>::InstanceAccessScope(
            bool coherent_access,
            bool ordered_access)
{
    //To implement
}

template<typename D>
TPresentation<D> TPresentation<D>::TopicAccessScope(
            bool coherent_access,
            bool ordered_access)
{
    //To implement
}

//TReliability
template<typename D>
TReliability<D>::TReliability(
            dds::core::policy::ReliabilityKind::Type kind,
            const dds::core::Duration& max_blocking_time)
    :  dds::core::Value<D>(kind, max_blocking_time) { }

template<typename D>
TReliability<D>::TReliability(
            const TReliability& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TReliability<D>& TReliability<D>::kind(
            dds::core::policy::ReliabilityKind::Type kind)
{
    //To implement
}

template<typename D>
dds::core::policy::ReliabilityKind::Type TReliability<D>::kind() const
{
    //To implement
}

template<typename D>
TReliability<D>& TReliability<D>::max_blocking_time(
            const dds::core::Duration& max_blocking_time)
{
    //To implement
}

template<typename D>
const dds::core::Duration TReliability<D>::max_blocking_time() const
{
    //To implement
}

template<typename D>
TReliability<D> TReliability<D>::Reliable(
            const dds::core::Duration& max_blocking_time)
{
    //To implement
}

template<typename D>
TReliability<D> TReliability<D>::BestEffort(
            const dds::core::Duration& max_blocking_time)
{
    //To implement
}

//TDestinationOrder

template<typename D>
TDestinationOrder<D>::TDestinationOrder(
            dds::core::policy::DestinationOrderKind::Type kind)
    : dds::core::Value<D>(kind) { }

template<typename D>
TDestinationOrder<D>::TDestinationOrder(
            const TDestinationOrder& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TDestinationOrder<D>& TDestinationOrder<D>::kind(
            dds::core::policy::DestinationOrderKind::Type kind)
{
    //To implement
}

template<typename D>
dds::core::policy::DestinationOrderKind::Type TDestinationOrder<D>::kind() const
{
    //To implement
}

template<typename D>
TDestinationOrder<D> TDestinationOrder<D>::SourceTimestamp()
{
    //To implement
}

template<typename D>
TDestinationOrder<D> TDestinationOrder<D>::ReceptionTimestamp()
{
    //To implement
}

//THistory
template<typename D>
THistory<D>::THistory(
            dds::core::policy::HistoryKind::Type kind,
            int32_t depth)
    : dds::core::Value<D>(kind, depth) { }

template<typename D>
THistory<D>::THistory(
            const THistory& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
dds::core::policy::HistoryKind::Type THistory<D>::kind() const
{
    //To implement
}

template<typename D>
THistory<D>& THistory<D>::kind(
            dds::core::policy::HistoryKind::Type kind)
{
    //To implement
}

template<typename D>
int32_t THistory<D>::depth() const
{
    //To implement
}

template<typename D>
THistory<D>& THistory<D>::depth(
            int32_t depth)
{
    //To implement
}

template<typename D>
THistory<D> THistory<D>::KeepAll()
{
    //To implement
}

template<typename D>
THistory<D> THistory<D>::KeepLast(
            uint32_t depth)
{
    //To implement
}

//TResourceLimits
template<typename D>
TResourceLimits<D>::TResourceLimits(
            int32_t max_samples,
            int32_t max_instances,
            int32_t max_samples_per_instance)
    :  dds::core::Value<D>(max_samples, max_instances, max_samples_per_instance) { }

template<typename D>
TResourceLimits<D>::TResourceLimits(
            const TResourceLimits& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TResourceLimits<D>& TResourceLimits<D>::max_samples(
            int32_t max_samples)
{
    //To implement
}

template<typename D>
int32_t TResourceLimits<D>::max_samples() const
{
    //To implement
}

template<typename D>
TResourceLimits<D>& TResourceLimits<D>::max_instances(
            int32_t max_instances)
{
    //To implement
}

template<typename D>
int32_t TResourceLimits<D>::max_instances() const
{
    //To implement
}

template<typename D>
TResourceLimits<D>& TResourceLimits<D>::max_samples_per_instance(
            int32_t max_samples_per_instance)
{
    //To implement
}

template<typename D>
int32_t TResourceLimits<D>::max_samples_per_instance() const
{
    //To implement
}

//TLiveliness
template<typename D>
TLiveliness<D>::TLiveliness(
            dds::core::policy::LivelinessKind::Type kind,
            const dds::core::Duration& lease_duration)
    : dds::core::Value<D>(kind, lease_duration) { }

template<typename D>
TLiveliness<D>::TLiveliness(
            const TLiveliness& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TLiveliness<D>& TLiveliness<D>::kind(
            dds::core::policy::LivelinessKind::Type kind)
{
    //To implement
}

template<typename D>
dds::core::policy::LivelinessKind::Type TLiveliness<D>::kind() const
{
    //To implement
}

template<typename D>
TLiveliness<D>& TLiveliness<D>::lease_duration(
            const dds::core::Duration& lease_duration)
{
    //To implement
}

template<typename D>
const dds::core::Duration TLiveliness<D>::lease_duration() const
{
    //To implement
}

template<typename D>
TLiveliness<D> TLiveliness<D>::Automatic()
{
    //To implement
}

template<typename D>
TLiveliness<D> TLiveliness<D>::ManualByParticipant(
            const dds::core::Duration& lease_duration)
{
    //To implement
}

template<typename D>
TLiveliness<D> TLiveliness<D>::ManualByTopic(
            const dds::core::Duration& lease_duration)
{
    //To implement
}


#ifdef OMG_DDS_PERSISTENCE_SUPPORT

//TDurabilityService

template<typename D>
TDurabilityService<D>::TDurabilityService(
    const dds::core::Duration& service_cleanup_delay,
    dds::core::policy::HistoryKind::Type history_kind,
    int32_t history_depth,
    int32_t max_samples,
    int32_t max_instances,
    int32_t max_samples_per_instance)
    : dds::core::Value<D>(service_cleanup_delay,
                          history_kind,
                          history_depth,
                          max_samples,
                          max_instances,
                          max_samples_per_instance) { }

template<typename D>
TDurabilityService<D>::TDurabilityService(
            const TDurabilityService& other)
    : dds::core::Value<D>(other.delegate()) { }

template<typename D>
TDurabilityService<D>& TDurabilityService<D>::service_cleanup_delay(
            const dds::core::Duration& service_cleanup_delay)
{
   //To implement
}

template<typename D>
const dds::core::Duration TDurabilityService<D>::service_cleanup_delay() const
{
    //To implement
}

template<typename D>
TDurabilityService<D>& TDurabilityService<D>::history_kind(
            dds::core::policy::HistoryKind::Type kind)
{
    //To implement
}

template<typename D>
dds::core::policy::HistoryKind::Type TDurabilityService<D>::history_kind() const
{
    //To implement
}

template<typename D>
TDurabilityService<D>& TDurabilityService<D>::history_depth(
            int32_t history_depth)
{
    //To implement
}

template<typename D>
int32_t TDurabilityService<D>::history_depth() const
{
    //To implement
}

template<typename D>
TDurabilityService<D>& TDurabilityService<D>::max_samples(
            int32_t max_samples)
{
    //To implement
}

template<typename D>
int32_t TDurabilityService<D>::max_samples() const
{
    //To implement
}

template<typename D>
TDurabilityService<D>& TDurabilityService<D>::max_instances(
            int32_t max_instances)
{
    //To implement
}

template<typename D>
int32_t TDurabilityService<D>::max_instances() const
{
    //To implement
}

template<typename D>
TDurabilityService<D>& TDurabilityService<D>::max_samples_per_instance(
            int32_t max_samples_per_instance)
{
    //To implement
}

template<typename D>
int32_t TDurabilityService<D>::max_samples_per_instance() const
{
    //To implement
}

#endif  // OMG_DDS_PERSISTENCE_SUPPORT


#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT

//TDataRepresentation

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
TDataRepresentation<D>::TDataRepresentation(
            const dds::core::policy::DataRepresentationIdSeq& value);

template<typename D>
TDataRepresentation<D>::TDataRepresentation(
            const TDataRepresentation& other)
    : dds::core::Value<D>(other.delegate()) { }

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
TDataRepresentation<D>& TDataRepresentation<D>::value(
            const dds::core::policy::DataRepresentationIdSeq& value);

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
const dds::core::policy::DataRepresentationIdSeq TDataRepresentation<D>::value() const;

#endif  // defined(OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT)

#ifdef OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT

//TTypeConsistencyEnforcement

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
TTypeConsistencyEnforcement<D>::TTypeConsistencyEnforcement(
            dds::core::policy::TypeConsistencyEnforcementKind::Type kind) { }

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
TTypeConsistencyEnforcement<D>& TTypeConsistencyEnforcement<D>::kind(
            dds::core::policy::TypeConsistencyEnforcementKind::Typekind) { }

/** @internal @bug OSPL-1746 Implementation required */
template<typename D>
dds::core::policy::TypeConsistencyEnforcementKind::Type TTypeConsistencyEnforcement<D>::kind() const { }

#endif  // defined(OMG_DDS_EXTENSIBLE_AND_DYNAMIC_TOPIC_TYPE_SUPPORT)

} //namespace policy
} //namespace core
} //namespace dds

#endif //EPROSIMA_DDS_CORE_POLICY_TCOREPOLICY_IMPL_HPP_
