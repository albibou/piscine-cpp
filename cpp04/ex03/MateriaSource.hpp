#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H
 
class MateriaSource
{
    public:
 
       MateriaSource(void);
       MateriaSource(MateriaSource const & src);
       ~MateriaSource(void);
 
       MateriaSource &  operator=(MateriaSource const & rhs);
 
   protected:
 
   private:
 
};
#endif // MATERIASOURCE_H

