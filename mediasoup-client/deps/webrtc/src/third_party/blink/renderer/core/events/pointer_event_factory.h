// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_POINTER_EVENT_FACTORY_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_POINTER_EVENT_FACTORY_H_

#include "third_party/blink/public/common/input/web_pointer_event.h"
#include "third_party/blink/public/common/input/web_pointer_properties.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/events/pointer_event.h"
#include "third_party/blink/renderer/platform/wtf/allocator/allocator.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"

namespace blink {

// Helper class for tracking the pointer ids for each type of PointerEvents.
// Using id re-mapping at this layer, this class makes sure that regardless of
// the domain of the id (i.e. in touch or pen) the corresponding pointer event
// will have a unique id amongst all pointer events as per pointer events'
// specification. This class intended to behave the same as existing browsers as
// much as possible for compatibility reasons. Particularly it behaves very
// similar to MS Edge to have pointer event ids generated by mouse always equal
// 1 and those that are generated by touch and pen will have increasing ids from
// 2.
class CORE_EXPORT PointerEventFactory {
  DISALLOW_NEW();

 public:
  // Returns the pointerType string for the PointerType enum.
  static const AtomicString& PointerTypeNameForWebPointPointerType(
      WebPointerProperties::PointerType type);

  PointerEventFactory();
  ~PointerEventFactory();

  // Returns nullptr if the |web_pointer_event| is invalid from event stream
  // perspective (e.g. it is a pointercancel for a non-existent id).
  PointerEvent* Create(const WebPointerEvent& web_pointer_event,
                       const Vector<WebPointerEvent>& coalesced_events,
                       const Vector<WebPointerEvent>& predicted_events,
                       LocalDOMWindow* view);

  PointerEvent* CreatePointerCancelEvent(const PointerId pointer_id,
                                         base::TimeTicks platfrom_time_stamp);

  // For creating raw update events in chorded button case.
  PointerEvent* CreatePointerRawUpdateEvent(PointerEvent*);

  // For creating capture events (i.e got/lostpointercapture).
  PointerEvent* CreatePointerCaptureEvent(PointerEvent*, const AtomicString&);

  // For creating boundary events (i.e pointerout/leave/over/enter).
  PointerEvent* CreatePointerBoundaryEvent(PointerEvent*,
                                           const AtomicString&,
                                           EventTarget*);

  // Clear all the existing ids.
  void Clear();

  // When a particular pointerId is removed, the id is considered free even
  // though there might have been other PointerEvents that were generated with
  // the same id before.
  bool Remove(const PointerId);

  // Returns all ids of pointers that are not hovering.
  Vector<PointerId> GetPointerIdsOfNonHoveringPointers() const;

  // Returns whether a pointer id exists and active.
  bool IsActive(const PointerId) const;

  // Returns whether a pointer id exists and has at least one pressed button.
  bool IsActiveButtonsState(const PointerId) const;

  // Returns the id of the pointer event corresponding to the given pointer
  // properties if exists otherwise s_invalidId.
  int GetPointerEventId(const WebPointerProperties&) const;

  // Returns pointerType of for the given pointerId if such id is active.
  // Otherwise it returns WebPointerProperties::PointerType::Unknown.
  WebPointerProperties::PointerType GetPointerType(PointerId pointer_id) const;

  // Returns whether a WebPoinerProperties is a primary pointer.
  bool IsPrimary(const WebPointerProperties&) const;

  static const PointerId kMouseId;
  static const PointerId kInvalidId;
  static const PointerId kReservedNonPointerId;

  // Removes pointer_id from the map.
  void RemoveLastPosition(const PointerId pointer_id);

  // Returns last_position of for the given pointerId if such id is active.
  // Otherwise it returns the PositionInScreen of the given events, so we will
  // get movement = 0 when there is no last position.
  FloatPoint GetLastPointerPosition(PointerId pointer_id,
                                    const WebPointerProperties& event,
                                    WebInputEvent::Type event_type) const;

  void SetLastPosition(PointerId pointer_id,
                       const FloatPoint& position_in_screen,
                       WebInputEvent::Type event_type);

 private:
  // We use int64_t to cover the whole range for PointerId with no
  // deleted hash value.
  template <typename T>
  using PointerIdKeyMap = HashMap<int64_t,
                                  T,
                                  WTF::IntHash<int64_t>,
                                  WTF::UnsignedWithZeroKeyHashTraits<int64_t>>;
  typedef struct IncomingId : public std::pair<int, int> {
    IncomingId() = default;
    IncomingId(WebPointerProperties::PointerType pointer_type, int raw_id)
        : std::pair<int, int>(static_cast<int>(pointer_type), raw_id) {}
    int PointerTypeInt() const { return first; }
    WebPointerProperties::PointerType GetPointerType() const {
      return static_cast<WebPointerProperties::PointerType>(first);
    }
    int RawId() const { return second; }
  } IncomingId;

  using IncomingIdToPointerIdMap =
      HashMap<IncomingId,
              PointerId,
              WTF::PairHash<int, int>,
              WTF::PairHashTraits<WTF::UnsignedWithZeroKeyHashTraits<int>,
                                  WTF::UnsignedWithZeroKeyHashTraits<int>>>;

  typedef struct PointerAttributes {
    IncomingId incoming_id;
    bool is_active_buttons;
    bool hovering;
    PointerAttributes()
        : incoming_id(), is_active_buttons(false), hovering(true) {}
    PointerAttributes(IncomingId incoming_id,
                      bool is_active_buttons,
                      bool hovering)
        : incoming_id(incoming_id),
          is_active_buttons(is_active_buttons),
          hovering(hovering) {}
  } PointerAttributes;

  PointerId AddIdAndActiveButtons(const IncomingId,
                                  bool is_active_buttons,
                                  bool hovering,
                                  WebInputEvent::Type event_type);
  bool IsPrimary(const PointerId) const;

  // Returns nullptr when the event is unexpected.  E.g. pointercancel for a
  // non-existent id (see crbug.com/1007164).
  PointerEventInit* ConvertIdTypeButtonsEvent(const WebPointerEvent&);

  void SetEventSpecificFields(PointerEventInit*, const AtomicString& type);

  // Creates pointerevents like boundary and capture events from another
  // pointerevent (i.e. up/down/move events).
  PointerEvent* CreatePointerEventFrom(PointerEvent*,
                                       const AtomicString&,
                                       EventTarget*);

  HeapVector<Member<PointerEvent>> CreateEventSequence(
      const WebPointerEvent& web_pointer_event,
      const PointerEventInit* pointer_event_init,
      const Vector<WebPointerEvent>& event_list,
      LocalDOMWindow* view);

  PointerId current_id_;
  IncomingIdToPointerIdMap pointer_incoming_id_mapping_;
  PointerIdKeyMap<PointerAttributes> pointer_id_mapping_;
  int primary_id_[static_cast<int>(
                      WebPointerProperties::PointerType::kMaxValue) +
                  1];
  int id_count_[static_cast<int>(WebPointerProperties::PointerType::kMaxValue) +
                1];

  PointerIdKeyMap<FloatPoint> pointer_id_last_position_mapping_;
  PointerIdKeyMap<FloatPoint> pointerrawupdate_last_position_mapping_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_POINTER_EVENT_FACTORY_H_
