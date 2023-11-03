#ifndef SAMPLE_H
# define SAMPLE_H

class   Sample{

public :

    int     public_foo;

    Sample(void);
    ~Sample(void);

    void    public_bar(void) const;

private :

    int     _private_foo;

    void    _private_bar(void) const;

};

#endif
