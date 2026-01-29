#pragma once

#define RUN_OK  (1)
#define RUN_END (0)
#define RUN_NG  (-1)

class Canes
{
public:
    Canes();
    ~Canes();

    bool Run();
};
