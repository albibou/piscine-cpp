#ifndef SAMPLE_H
# define SAMPLE_H

class   Sample{

public :
    
    Sample(void);
    ~Sample(void);

    static int  get_nbInst(void);

private :

    static int  _nbInst;

};

#endif
