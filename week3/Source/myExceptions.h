class end_of_file : public std::exception {
public:
    end_of_file():
            s{ std::string{ "end of file" }}
    {}

    const char * what() const noexcept override {
        return s.c_str();
    }

private:
    std::string s;
};

class unknown_color : public std::exception {
public:
    unknown_color( const std::string & name  ):
            s{ std::string{ "unknown color [" } + name + "]" }
    {}


    const char * what() const noexcept override {
        return s.c_str();
    }
private:
    std::string s;
};

class invalid_position : public std::exception {
public:
    invalid_position( char c  ):
            s{ std::string{ "invalid position [" } + c + "]" }
    {}

    const char * what() const noexcept override {
        return s.c_str();
    }
private:
    std::string s;
};

class char_not_completable : public std::exception {
public:
    char_not_completable( char c  ):
            s{ std::string{ "input and char are not completable [" } + c + "]" }
    {}
    const char * what() const noexcept override {
        return s.c_str();
    }
private:
    std::string s;
};

class unknown_shape : public std::exception {
public:
    unknown_shape(const char * name):
            s{ std::string{ "name of shape is not valid [" }+ name + "]"}
    {}
    const char * what() const noexcept override {
        return s.c_str();
    }
private:
    std::string s;
};
