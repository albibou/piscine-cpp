#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H
 
class IMateriaSource
{
    public:
 
       IMateriaSource(void);
       IMateriaSource(IMateriaSource const & src);
       ~IMateriaSource(void);
 
       IMateriaSource &  operator=(IMateriaSource const & rhs);
 
   protected:
 
   private:
 
};
#endif // IMATERIASOURCE_H

