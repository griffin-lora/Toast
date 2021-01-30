#pragma once
#include <iostream>
#include <exception>
#include <vector>
#include <sstream>

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
        STRING,
        FLOAT,
        FUNC,
        ARRAY
    };

    class StateTypeHolder {
        private:
            StateType main_type;
            std::vector<StateTypeHolder> return_type;
            std::vector<StateTypeHolder> func_args;
        public:
            StateTypeHolder(StateType main_type);
            void func_init(StateTypeHolder return_type, std::vector<StateTypeHolder> func_args);
            StateType get_main_type();
            StateTypeHolder get_return_type();
            std::vector<StateTypeHolder> get_func_args();
            bool equals(StateTypeHolder type);
            bool equals(StateType type);
    };


    enum InstructionType {
        NONE,
        PUSH,
        POP,
        SET,
        MOVE,
        CALL,
        EXIT,
        FRAME,
        BACK,
        SKIP
    };

    class Instruction {
        private:
            InstructionType type;
            std::vector<int> args;
            std::string str;
        public:
            Instruction(InstructionType type, std::vector<int> args);
            Instruction(InstructionType type, std::vector<int> args, std::string str);
            InstructionType get_type();
            std::vector<int> get_args();
            std::string get_string();
    };

    std::string make_human_readable(Instruction instruction);

}