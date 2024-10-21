// +----------------+        +----------------+
// |    Subject     |        |   Subscriber   |
// +----------------+        +----------------+
// | - state        |        |                |
// | - observers[]  |<-------|  update()      |
// +----------------+        +----------------+
// | + addObserver()|        |                |
// | + removeObserver()      |                |
// | + notify()     |        |                |
// +----------------+        +----------------+

class Subscriber
{
public:
    virtual void notify(std::string &msg)=0;
};

class User : public Subscriber
{
    int m_userId;
public:
    User(int userId) : m_userId{userId} {}
    void notify(std::string &msg) override
    {
        std::cout << "User with id " << m_userId <<" notified"<< msg <<"\n";
    }
};

class Subject{
    list<Subscriber*> m_subscribers;
    void Subscribe(Subscriber* subscriber)
    {
        m_subscribers.add(subscriber);
    }
    void UnSubscribe(Subscriber* subscriber)
    {
        m_subscribers.remove(subscriber);
    }
    void StateChange(std::string &msg)
    {
        for(auto &subscriber: m_subscribers)
        {
            subscriber->notify(msg);
        }
    }
};