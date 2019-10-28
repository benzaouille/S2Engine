#ifndef SINGLETON_H_
#define SINGLETON_H_

namespace Core
{
  template<typename T>
  class Singleton
  {
  public:
    static T& getInstance()
    {
        //une variable static est thread safe (même si dans notre contexte ce n'est pas utile..)
        static T instance;
        return instance;
    }
    Singleton(Singleton&&) ;

  protected:
    Singleton (){};
	  ~Singleton(){};

  private:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton) = delete;
  };
};

#endif //SINGLETON_H_
