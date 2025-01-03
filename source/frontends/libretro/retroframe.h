#pragma once

#include "frontends/common2/gnuframe.h"

#include <vector>

namespace ra2
{

  class RetroFrame : public common2::GNUFrame
  {
  public:
    RetroFrame(const common2::EmulatorOptions & options);

    void VideoPresentScreen() override;
    void FrameRefreshStatus(int drawflags) override;
    void Initialize(bool resetVideoState) override;
    void Destroy() override;
    void Begin() override;
    int FrameMessageBox(LPCSTR lpText, LPCSTR lpCaption, UINT uType) override;
    void GetBitmap(WORD id, LONG cb, LPVOID lpvBits) override;

    std::shared_ptr<SoundBuffer> CreateSoundBuffer(DWORD dwFlags, DWORD dwBufferSize, DWORD nSampleRate, int nChannels, LPCSTR pStreamName) override;

  protected:
    virtual void SetFullSpeed(const bool value) override;
    virtual bool CanDoFullSpeed() override;

  private:
    std::vector<uint8_t> myVideoBuffer;

    size_t myPitch;
    size_t myOffset;
    size_t myHeight;
    size_t myBorderlessWidth;
    size_t myBorderlessHeight;
    uint8_t* myFrameBuffer;
  };

}
