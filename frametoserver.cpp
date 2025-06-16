#include "frametoserver.h"

FrameToServer::FrameToServer()
    : FrameToServer(0, true, false, 0.0, 0.0)
{

}

FrameToServer::FrameToServer(int _krok, bool _isTimerEnabled, bool _isReseted, double _sygn_zadany, double _pid)
    : krok_symulacji{_krok}
    , isTimerEnabled{_isTimerEnabled}
    , isReseted{_isReseted}
    , sygn_zadany{_sygn_zadany}
    , pid{_pid}
{

}
