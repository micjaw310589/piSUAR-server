#ifndef FRAMETOSERVER_H
#define FRAMETOSERVER_H

#endif // FRAMETOSERVER_H

struct FrameToServer {
    int krok_symulacji;
    double sygn_zadany;
    double pid;

    FrameToServer();
    FrameToServer(int _krok, double _sygn_zadany, double _pid);
};
