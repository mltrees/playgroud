// ifstream constructor.
#include <pthread.h>
#include <iostream>     // std::cout
#include <sstream>
#include <thread>


static void my_data_destructor(void* data) {
    std::cout << "destruct data" << std::endl;
    return;
}

static pthread_key_t tls_key;
static pthread_once_t key_once = PTHREAD_ONCE_INIT;

void make_key()
{
    (void) pthread_key_create(&tls_key, my_data_destructor);
}

int test() {
    pthread_once(&key_once, make_key);
    void *ptr = nullptr;
    if ((ptr = pthread_getspecific(tls_key)) == nullptr) {
        ptr = malloc(sizeof(std::thread::id));
        std::thread::id* i_ptr = static_cast<std::thread::id*>(ptr);
        *i_ptr = std::this_thread::get_id();
        (void) pthread_setspecific(tls_key, ptr);
    }

    if (ptr == nullptr) {
        std::cout << "ptr is null" << std::endl;
    } else {
        std::cout << "ptr = " << *(static_cast<std::thread::id*>(ptr)) << std::endl;
    }
    return 0;
}

int main () {
    // test();

    std::thread t(test);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::thread t1(test);

    t.join();
    t1.join();


    return 0;
}
