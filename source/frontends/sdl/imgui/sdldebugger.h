#include "frontends/sdl/imgui/glselector.h"
#include "frontends/sdl/imgui/inputtexthistory.h"
#include "Debugger/Debug.h"

#include <unordered_map>

namespace sa2
{

  class SDLFrame;

  class ImGuiDebugger
  {
  public:
    bool showDebugger = false;

    void drawDebugger(SDLFrame* frame);
    void resetDebuggerCycles();

    void syncDebuggerState(SDLFrame* frame);

  private:
    bool mySyncCursor = true;
    bool myScrollConsole = true;

    int64_t myBaseDebuggerCycles;
    std::unordered_map<DWORD, int64_t> myAddressCycles;

    InputTextHistory myInputTextHistory;

    void debuggerCommand(SDLFrame * frame, const char * s);

    void drawDisassemblyTable(SDLFrame * frame);
    void drawConsole();
    void drawBreakpoints();
    void drawRegisters();
    void drawStackReturnAddress();
    void drawAnnunciators();
    void drawSwitches();

    void processDebuggerKeys();

    void setCurrentAddress(const DWORD nAddress);
 };

}