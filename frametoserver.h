#ifndef FRAMETOSERVER_H
#define FRAMETOSERVER_H

struct FrameToServer {
    int krok_symulacji;
    bool isTimerEnabled;
    bool isReseted;
    double sygn_zadany;
    double pid;

    FrameToServer();
    FrameToServer(int _krok, bool _isTimerEnabled, bool _isReseted, double _sygn_zadany, double _pid);
};


#endif // FRAMETOSERVER_H

