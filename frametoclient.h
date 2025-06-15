#ifndef FRAMETOCLIENT_H
#define FRAMETOCLIENT_H

struct FrameToClient
{
    int krok_symulacji;
    double sygn_regulowany;

    FrameToClient();
    FrameToClient(int _krok_symulacji, double _sygn_regulowany);
};

#endif // FRAMETOCLIENT_H
