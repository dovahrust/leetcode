constexpr size_t CNT = 5;

class DiningPhilosophers {
    mutex mtxs[CNT];
public:
    DiningPhilosophers() {

    }

    void wantsToEat(
        int philosopher,
        function<void()> pick_left_fork,
        function<void()> pick_right_fork,
        function<void()> eat,
        function<void()> put_left_fork,
        function<void()> put_right_fork
    ) {
        size_t lower_fork = 0;
        size_t upper_fork = 0;
		if (philosopher == 0) {
            lower_fork = 0;
            upper_fork = CNT - 1;
        } else {
            lower_fork = static_cast<size_t>(philosopher - 1);
            upper_fork = static_cast<size_t>(philosopher);
        };

        auto l = std::lock_guard(mtxs[lower_fork]);
        auto r = std::lock_guard(mtxs[upper_fork]);
        pick_left_fork();
        pick_right_fork();
        eat();
        put_left_fork();
        put_right_fork();
    }
};
