#include <iostream>

class bananeException : public std::exception{

  
  public :
    virtual const char * what() const throw(){
      return ("Il s'agit de l'exception banane");
    }

};


int main(int argc, char **argv){

  (void)argv;

  try {
    switch (argc){ 
      case 1 :
        throw std::exception();
        break ;
      case 2 :
        throw bananeException();
        break ;
      default :
        break ;
    }
  }
  catch (const bananeException& e){
    std::cout << e.what() << std::endl;
    return (2);
  }
  catch (const std::exception& e) {
    std::cout << "Exception was catched" << std::endl;
    return (1);
  }
  return (0);
}
