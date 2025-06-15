#include "frametoserver.h"

FrameToServer::FrameToServer()
    : FrameToServer(0, 0.0, 0.0)
{

}

FrameToServer::FrameToServer(int _krok, double _sygn_zadany, double _pid)
    : krok_symulacji{_krok}
    , sygn_zadany{_sygn_zadany}
    , pid{_pid}
{

}
