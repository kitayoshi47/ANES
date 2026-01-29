#define SafeDelete(_p)      if (_p) { delete _p; _p = NULL; }
#define SafeDeleteArray(_p) if (_p) { delete[] _p; _p = NULL; }
