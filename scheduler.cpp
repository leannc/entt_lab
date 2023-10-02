//
// Created by wangkang on 2023/10/2.
//

#include "Scene.h"

struct my_process: entt::process<my_process, std::uint32_t> {
    using delta_type = std::uint32_t;

    my_process(delta_type delay)
            : remaining{delay}
    {}

    void update(delta_type delta, void *) {
        remaining -= std::min(remaining, delta);

        // ...
        std::cout<<std::this_thread::get_id() <<": remaining " << remaining << std::endl;

        if(!remaining) {
            succeed();
        }

        if(remaining==1)
        {
            fail();
        }

    }

    void init()
    {
        std::cout<<"inited " << remaining << std::endl;
    }

    void succeeded()
    {
        std::cout<<"succeeded " << remaining << std::endl;
    }

    void failed()
    {
        std::cout<<"failed " << remaining << std::endl;
    }

    void aborted()
    {
        std::cout<<"aborted " << remaining << std::endl;
    }


private:
    delta_type remaining;
};

void lambda_succeed()
{
    std::cout<<"lambda succeed " << std::endl;
}

/**
 * schedular都是在一个线程里面完成的，执行顺序是LIFO，也就是最后attach的最先执行.
 * 在chain process的时候，只有上一个是succeed，才会执行后面所有的。
 * */
void Scene::use_case_scheduler() {

    entt::scheduler<std::uint32_t> scheduler;

    // checks if there are processes still running
    const auto empty = scheduler.empty();
    std::cout<<"scheduler empty " << empty << std::endl;

// gets the number of processes still running
    entt::scheduler<std::uint32_t>::size_type size = scheduler.size();
    std::cout<<"scheduler size " << size << std::endl;


// resets the scheduler to its initial state and discards all the processes
    scheduler.clear();

// attach a process
    scheduler.attach<my_process>(1000u);
    scheduler.attach<my_process>(1001u);

    size = scheduler.size();
    std::cout<<"scheduler size " << size << std::endl;

// schedules a task in the form of a lambda function
    scheduler.attach([](auto delta, void *, auto succeed, auto fail) {
                // ...
                std::cout<<"lambda task 1" << std::endl;
                succeed();
            })
// appends a child in the form of another lambda function
            .then([](auto delta, void *, auto succeed, auto fail) {
                std::cout<<"lambda task 2" << std::endl;
                fail();
            })

            .then([](auto delta, void *, auto succeed, auto fail) {
                std::cout<<"lambda task 3" << std::endl;
                succeed();
            })
// appends a child in the form of a process class
            .then<my_process>(1002u);


    size = scheduler.size();
    std::cout<<"scheduler size " << size << std::endl;

    std::cout<<"------------start-------------------"<<std::endl;
    while (true)
    {
        // updates all the processes, no user data are provided
        scheduler.update(100, nullptr);

        //判断scheduler是否已经全部结束
        if(scheduler.empty())
        {
            break;
        }

//// updates all the processes and provides them with custom data
//        scheduler.update(delta, &data);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout<<"------------end use case scehdular-------------------"<<std::endl;
}