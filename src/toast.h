#include <iostream>
#include <exception>
#include <vector>

namespace toast {
    typedef unsigned char byte;
    typedef unsigned int arg;
    
    class Exception : public std::exception {
        private:
            const char* msg;
        public:
            Exception(const char* msg);
            const char* what() const throw();
    };

    enum StateType {
        VOID,
        INT,
        BOOL,
        FUNC
    };

    class StateTypeHolder {
        private:
            StateType main_type;
            StateTypeHolder* return_type;
            std::vector<StateTypeHolder*> func_args;
        public:
            StateTypeHolder(StateType main_type);
            void func_init(StateTypeHolder* return_type, std::vector<StateTypeHolder*> func_args);
            StateType get_main_type();
            StateTypeHolder* get_return_type();
            std::vector<StateTypeHolder*> get_func_args();
            bool equals(StateTypeHolder* type);
            bool equals(StateType type);
    };
}