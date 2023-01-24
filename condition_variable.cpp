#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money){

while(true){
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::lock_guard<mutex> lg(m);
  balance+=money;
  std::cout << "Amount added current balance: " << balance << endl;
  cv.notify_one();
  }
}

void withdrawMoney(int money){
while(true){
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, [] { return (balance!=0) ? true: false;});
    if(balance >= money){
        balance -=money;
        cout << "AMount deducted: " << money << endl;
       } else{
       cout << "Amount can't be decucted, current balance is less than " << money << endl;
       }

       cout << "Current balance is : " << balance << endl;
  }
}


int main() {
  cout << "Hello World!\n";
  
  std::thread t1(withdrawMoney, 600);
  std::thread t2(addMoney, 500);
  t1.join();
  t2.join();
  return 0;
}
