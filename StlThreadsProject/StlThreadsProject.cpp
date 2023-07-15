#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <typeinfo>

using namespace std;

void func()
{
    
    for (int i = 0; i < 100; i++)
    {
        cout << "\t" << this_thread::get_id() << " " << i << "\n";
    }
    
}

int num{};

void funcSum()
{
    
    for (int i = 0; i < 3000; i++)
    {
        //m.lock();
        mutex m;
        lock_guard<mutex> lg(m);
        cout << this_thread::get_id() << " " << num << "\n";
        num++;
        //m.unlock();
    }
    
}

int Sum(int n)
{
    cout << this_thread::get_id() << "\n";
    int result{};
    for (int i = 1; i <= n; i++)
    {
        result += i;
        this_thread::sleep_for(100ms);
    }
    return result;
}

int main()
{
    /*cout << num << "\n";
    thread th1(funcSum);
    thread th2(funcSum);
    th1.join();
    th2.join();
    cout << num << "\n";*/

    /*for (int i = 0; i < 100; i++)
    {
        cout << this_thread::get_id() << " " << i << "\n";
    }
    th1.detach();*/

    //jthread th3(func, 100, 200);

    cout << this_thread::get_id() << "\n";

    auto as1 = async(Sum, 100);
    //as1.wait();
    //int a = as1.get();
    auto as2 = async(Sum, 100);
    cout << as1.get() << "\n";
    cout << as2.get() << "\n";
    //auto as2 = async(func);
}
