#ifndef SAMPLE_H
# define SAMPLE_H

class   Sample{

public :

    Sample(void);
    ~Sample(void);

    int get_foo(void) const;
    void    set_foo(int i);

private :

    int _foo;

};

#endif
