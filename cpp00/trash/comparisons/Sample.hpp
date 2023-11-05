#ifndef SAMPLE_H
# define SAMPLE_H

class   Sample{

public :

    Sample(int i);
    ~Sample(void);

    int     get_foo(void) const;
    bool    compare(Sample *other) const;

private :

    int _foo;

};

#endif
