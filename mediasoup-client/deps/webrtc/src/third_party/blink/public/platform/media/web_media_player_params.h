// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_PUBLIC_PLATFORM_MEDIA_WEB_MEDIA_PLAYER_PARAMS_H_
#define THIRD_PARTY_BLINK_PUBLIC_PLATFORM_MEDIA_WEB_MEDIA_PLAYER_PARAMS_H_

#include <stdint.h>

#include "base/callback.h"
#include "base/feature_list.h"
#include "base/memory/ref_counted.h"
#include "base/memory/weak_ptr.h"
#include "cc/layers/surface_layer.h"
#include "components/viz/common/gpu/raster_context_provider.h"
#include "media/base/media_log.h"
#include "media/base/media_observer.h"
#include "media/base/media_switches.h"
#include "media/base/routing_token_callback.h"
#include "media/mojo/mojom/media_metrics_provider.mojom.h"
#include "mojo/public/cpp/bindings/pending_remote.h"
#include "third_party/blink/public/platform/media/power_status_helper.h"
#include "third_party/blink/public/platform/web_common.h"
#include "third_party/blink/public/platform/web_media_player.h"
#include "third_party/blink/public/platform/web_video_frame_submitter.h"

namespace base {
class SingleThreadTaskRunner;
class TaskRunner;
}

namespace media {
class Demuxer;
class SwitchableAudioRendererSink;
}  // namespace media

namespace blink {
class WebContentDecryptionModule;
class WebSurfaceLayerBridge;
class WebSurfaceLayerBridgeObserver;

using CreateSurfaceLayerBridgeCB =
    base::OnceCallback<std::unique_ptr<WebSurfaceLayerBridge>(
        WebSurfaceLayerBridgeObserver*,
        cc::UpdateSubmissionStateCB)>;

// Holds parameters for constructing WebMediaPlayerImpl without having
// to plumb arguments through various abstraction layers.
class BLINK_PLATFORM_EXPORT WebMediaPlayerParams {
 public:
  // Returns true if load will deferred. False if it will run immediately.
  using DeferLoadCB = base::RepeatingCallback<bool(base::OnceClosure)>;

  // Callback to tell V8 about the amount of memory used by the WebMediaPlayer
  // instance.  The input parameter is the delta in bytes since the last call to
  // AdjustAllocatedMemoryCB and the return value is the total number of bytes
  // used by objects external to V8.  Note: this value includes things that are
  // not the WebMediaPlayer!
  using AdjustAllocatedMemoryCB = base::RepeatingCallback<int64_t(int64_t)>;

  // |defer_load_cb|, |audio_renderer_sink|, |compositor_task_runner|, and
  // |context_3d_cb| may be null.
  WebMediaPlayerParams(
      std::unique_ptr<media::MediaLog> media_log,
      const DeferLoadCB& defer_load_cb,
      const scoped_refptr<media::SwitchableAudioRendererSink>&
          audio_renderer_sink,
      const scoped_refptr<base::SingleThreadTaskRunner>& media_task_runner,
      const scoped_refptr<base::TaskRunner>& worker_task_runner,
      const scoped_refptr<base::SingleThreadTaskRunner>& compositor_task_runner,
      const scoped_refptr<base::SingleThreadTaskRunner>&
          video_frame_compositor_task_runner,
      const AdjustAllocatedMemoryCB& adjust_allocated_memory_cb,
      WebContentDecryptionModule* initial_cdm,
      media::RequestRoutingTokenCallback request_routing_token_cb,
      base::WeakPtr<media::MediaObserver> media_observer,
      bool enable_instant_source_buffer_gc,
      bool embedded_media_experience_enabled,
      mojo::PendingRemote<media::mojom::MediaMetricsProvider> metrics_provider,
      CreateSurfaceLayerBridgeCB bridge_callback,
      scoped_refptr<viz::RasterContextProvider> raster_context_provider,
      WebMediaPlayer::SurfaceLayerMode use_surface_layer_for_video,
      bool is_background_suspend_enabled,
      bool is_background_video_play_enabled,
      bool is_background_video_track_optimization_supported,
      std::unique_ptr<media::Demuxer> demuxer_override,
      std::unique_ptr<PowerStatusHelper> power_status_helper);

  WebMediaPlayerParams(const WebMediaPlayerParams&) = delete;
  WebMediaPlayerParams& operator=(const WebMediaPlayerParams&) = delete;
  ~WebMediaPlayerParams();

  DeferLoadCB defer_load_cb() const { return defer_load_cb_; }

  const scoped_refptr<media::SwitchableAudioRendererSink>& audio_renderer_sink()
      const {
    return audio_renderer_sink_;
  }

  std::unique_ptr<media::MediaLog> take_media_log() {
    return std::move(media_log_);
  }

  mojo::PendingRemote<media::mojom::MediaMetricsProvider>
  take_metrics_provider() {
    return std::move(metrics_provider_);
  }

  const scoped_refptr<base::SingleThreadTaskRunner>& media_task_runner() const {
    return media_task_runner_;
  }

  const scoped_refptr<base::TaskRunner> worker_task_runner() const {
    return worker_task_runner_;
  }

  const scoped_refptr<base::SingleThreadTaskRunner>& compositor_task_runner()
      const {
    return compositor_task_runner_;
  }

  const scoped_refptr<base::SingleThreadTaskRunner>&
  video_frame_compositor_task_runner() const {
    return video_frame_compositor_task_runner_;
  }

  WebContentDecryptionModule* initial_cdm() const { return initial_cdm_; }

  AdjustAllocatedMemoryCB adjust_allocated_memory_cb() const {
    return adjust_allocated_memory_cb_;
  }

  base::WeakPtr<media::MediaObserver> media_observer() const {
    return media_observer_;
  }

  bool enable_instant_source_buffer_gc() const {
    return enable_instant_source_buffer_gc_;
  }

  bool embedded_media_experience_enabled() const {
    return embedded_media_experience_enabled_;
  }

  media::RequestRoutingTokenCallback request_routing_token_cb() {
    return request_routing_token_cb_;
  }

  CreateSurfaceLayerBridgeCB create_bridge_callback() {
    return std::move(create_bridge_callback_);
  }

  scoped_refptr<viz::RasterContextProvider> raster_context_provider() {
    return raster_context_provider_;
  }

  WebMediaPlayer::SurfaceLayerMode use_surface_layer_for_video() const {
    return use_surface_layer_for_video_;
  }

  bool IsBackgroundSuspendEnabled() const {
    return is_background_suspend_enabled_;
  }

  bool IsBackgroundVideoPlaybackEnabled() const {
    return is_background_video_playback_enabled_;
  }

  bool IsBackgroundVideoTrackOptimizationSupported() const {
    return is_background_video_track_optimization_supported_;
  }

  std::unique_ptr<media::Demuxer> TakeDemuxerOverride();

  std::unique_ptr<PowerStatusHelper> TakePowerStatusHelper() {
    return std::move(power_status_helper_);
  }

 private:
  DeferLoadCB defer_load_cb_;
  scoped_refptr<media::SwitchableAudioRendererSink> audio_renderer_sink_;
  std::unique_ptr<media::MediaLog> media_log_;
  scoped_refptr<base::SingleThreadTaskRunner> media_task_runner_;
  scoped_refptr<base::TaskRunner> worker_task_runner_;
  scoped_refptr<base::SingleThreadTaskRunner> compositor_task_runner_;
  scoped_refptr<base::SingleThreadTaskRunner>
      video_frame_compositor_task_runner_;
  AdjustAllocatedMemoryCB adjust_allocated_memory_cb_;

  WebContentDecryptionModule* initial_cdm_;
  media::RequestRoutingTokenCallback request_routing_token_cb_;
  base::WeakPtr<media::MediaObserver> media_observer_;
  bool enable_instant_source_buffer_gc_;
  const bool embedded_media_experience_enabled_;
  mojo::PendingRemote<media::mojom::MediaMetricsProvider> metrics_provider_;
  CreateSurfaceLayerBridgeCB create_bridge_callback_;
  scoped_refptr<viz::RasterContextProvider> raster_context_provider_;
  WebMediaPlayer::SurfaceLayerMode use_surface_layer_for_video_;

  // Whether the renderer should automatically suspend media playback in
  // background tabs.
  bool is_background_suspend_enabled_ = false;
  // Whether the renderer is allowed to play video in background tabs.
  bool is_background_video_playback_enabled_ = true;
  // Whether background video optimization is supported on current platform.
  bool is_background_video_track_optimization_supported_ = true;

  // Optional custom demuxer to use instead of the standard demuxers.
  std::unique_ptr<media::Demuxer> demuxer_override_;

  std::unique_ptr<PowerStatusHelper> power_status_helper_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_PUBLIC_PLATFORM_MEDIA_WEB_MEDIA_PLAYER_PARAMS_H_
