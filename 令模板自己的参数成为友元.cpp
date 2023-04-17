// 网络库基类
template <typename T>
class Network {
    // 私有通信细节
    void priv_communicate() { ... }  

public:
    // 公共接口
    void communicate() { ... }
};

// 客户端类 
class Client : public Network<Client> {
    friend Server;   // 令服务器类型为友元类型
    void priv_communicate() { ... }
    
public:
    void client_communicate_with_server() {
        priv_communicate();
    }     
};  

// 服务器类
class Server { 
public:
    void server_communicate(Client& c) {
        // 可以访问客户端私有成员
        c.client_communicate_with_server();  
    }
};

void client_func() {
    Client c;    
    Server s;
    c.communicate();    // 使用公共接口

    // 客户端与特定服务器通信
    s.server_communicate(c); 
}