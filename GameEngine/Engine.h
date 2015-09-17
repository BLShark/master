#ifndef ENGINE_H
#define ENGINE_H


class Engine
{
  unsigned long m_lTimer;
  
public:
  Engine();
  ~Engine(){};
  
  void Process(int interval);
  
  
};

#endif // ENGINE_H
