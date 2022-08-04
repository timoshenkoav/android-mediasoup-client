// Copyright 2021 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_HTML_CUSTOM_CUSTOM_STATE_SET_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_HTML_CUSTOM_CUSTOM_STATE_SET_H_

#include "third_party/blink/renderer/bindings/core/v8/iterable.h"
#include "third_party/blink/renderer/platform/bindings/script_wrappable.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

class CustomStateIterationSource;
class Element;

// This class is an implementation of 'CustomStateSet' IDL interface.
class CustomStateSet final : public ScriptWrappable,
                             public SetlikeIterable<String> {
  DEFINE_WRAPPERTYPEINFO();

 public:
  explicit CustomStateSet(Element& element);
  void Trace(Visitor* visitor) const override;

  // IDL bindings:
  //
  // This operation is O(size()).
  void add(const String& value, ExceptionState& exception_state);
  uint32_t size() const;
  void clearForBinding(ScriptState*, ExceptionState&);
  // This operation is O(size()).
  bool deleteForBinding(ScriptState*, const String& value, ExceptionState&);
  // This operation is O(size()).
  bool hasForBinding(ScriptState*, const String& value, ExceptionState&) const;

  // This operation is O(size()).
  bool Has(const String& value) const;

 private:
  // blink::Iterable override:
  IterationSource* StartIteration(ScriptState* state, ExceptionState&) override;

  void InvalidateStyle() const;

  Member<Element> element_;
  // We use neither LinkedHashSet nor ListHashSet because it's difficult to
  // implement "live" iterators with them.
  // See crbug.com/1184020.
  //
  // If the O(size()) operations are problematic, we should change the type of
  // the following data member.
  Vector<String> list_;
  HeapHashSet<WeakMember<CustomStateIterationSource>> iterators_;

  friend class CustomStateIterationSource;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_HTML_CUSTOM_CUSTOM_STATE_SET_H_
