#pragma once

#define ANES_VER "0.00"

class Canes
{
public:
    struct InitDesc {
        int val = 0;
    };

public:
    Canes();
    ~Canes();

    void Initialize(InitDesc& desc);
    void Run();
    void Finalize();
};
