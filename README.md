<!-- 42 libft -->
<h1 align="center">LIBFT</h1>

<!-- ABOUT THE PROJECT -->
## ABOUT PHILOSOPHERS
The Dining Philosophers problem is a classic programming challenge that showcases the complexities of managing multiple threads and concurrent access to shared resources. It involves a scenario where five philosophers sit around a table, each having a plate and a fork. To eat, a philosopher needs both neighboring forks. The task is to prevent conflicts and deadlocks as philosophers attempt to pick up the required forks simultaneously.

Solving this problem requires implementing synchronization techniques like locks or semaphores to ensure that philosophers can safely access forks without causing issues like deadlocks. The project helps programming students grasp essential concepts of multi-threading and gain practical experience in handling concurrency challenges in software systems.

<!-- install section -->
## HOW TO COMPILE PHILO
---
1. Clone the repo
    ```
    $ git clone https://github.com/axhar005/philosophers.git
    ```
2. Change _**<libft_directory>**_ and run the _**make**_ command. The program will generate the library _**libft.a**_
    ```
    $ cd <philo_directory>
    $ make
    ```

### HOW TO USE
---
1. "Philo" requires four parameters and an optional fifth one. There should be no more than 200 "philo" instances, and the values of the other three parameters should not be below 60. The last parameter is unlimited, with a maximum value of int.
    ````
    ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
    ````


