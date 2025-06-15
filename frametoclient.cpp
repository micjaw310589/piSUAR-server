#include "frametoclient.h"

FrameToClient::FrameToClient()
    : FrameToClient(0, 0.0)
{}

FrameToClient::FrameToClient(int _krok_symulacji, double _sygn_regulowany)
    : krok_symulacji{_krok_symulacji}
    , sygn_regulowany{_sygn_regulowany}
{}
