#pragma once

#include <string>

class FractionException {
    private:
        std::string m_error;

    public:
        FractionException(std::string error) : m_error(error) {}

        const std::string getError() {return m_error;}
};
