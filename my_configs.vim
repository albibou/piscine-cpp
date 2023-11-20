" Set colorscheme 

try
    colorscheme gruvbox
catch
endtry

" Show number of line
set number

"Activate the mouse
set mouse=a

"Split below
set splitbelow

"Split on right
set splitright

"C++ Class Generator                                                                                                    
 function! Class(ClassName)                                                                                              
    "==================  editing header file =====================                                                       
     let header = a:ClassName.".hpp"                                                                                                                                                                                                                                                                                        
     :vsp %:h/.hpp                                                                                                                                                                                                                             
     call append(0,"#ifndef ".toupper(a:ClassName)."_H")                                                                 
     call append(1,"# define ".toupper(a:ClassName)."_H")                                                           
     call append(2," ")                                                                                                  
     call append(3,"class ".a:ClassName )                                                                                
     call append(4, "{")                                                                                                 
     call append(5, "   public:")                                                                                        
     call append(6," ")                                                                                             
     call append(7, "      ".a:ClassName."(void);")                                                                          
     call append(8, "      ~".a:ClassName."(void);")                                                                 
     call append(9," ")                                                                                             
     call append(10, "   private:")                                                                                       
     call append(11, "};")                                                                                               
     call append(12," ")                                                                                             
     call append(13,"#endif // ".toupper(a:ClassName)."_H")                                                              
     :execute 'write' header                                                                                             
   "================== editing source file ========================                                                      
     let src    = a:ClassName.".cpp"                                                                                     
     :vsp %:h/.cpp                                                                                                                                                                                                                     
     :execute "normal! a#include \"" . a:ClassName . ".hpp\"\<cr>\<cr>"
     call append(1," ")                                                                                                   
     call append(2,a:ClassName."::".a:ClassName."(void){")                                                                           
     call append(3," ")                                                                                                   
     call append(4,"    return ;")                                                                                             
     call append(5,"}")                                                                                                   
     call append(6," ")                                                                                                   
     call append(7,a:ClassName."::~".a:ClassName."(void){")                                                                         
     call append(8,"")                                                                                                   
     call append(9,"    return ;")                                                                                            
     call append(10,"}")                                                                                                  
     :execute 'write' src
 endfunction

command! -nargs=1 Class call Class(<f-args>) 

"C++ Canonical Class Generator                                                                                                    
 function! Cclass(ClassName)                                                                                              
    "==================  editing header file =====================                                                       
     let header = a:ClassName.".hpp"                                                                                                                                                                                                                                                                                        
     :vsp %:h/.hpp                                                                                                                                                                                                                            
     call append(0,"#ifndef ".toupper(a:ClassName)."_H")                                                                 
     call append(1,"# define ".toupper(a:ClassName)."_H")                                                           
     call append(2," ")                                                                                                  
     call append(3,"class ".a:ClassName )                                                                                
     call append(4, "{")                                                                                                 
     call append(5, "   public:")                                                                                        
     call append(6," ")                                                                                             
     call append(7, "      ".a:ClassName."(void);")                                                                          
     call append(8, "      ".a:ClassName."(".a:ClassName. " const & src);")                                                                          
     call append(9, "      ~".a:ClassName."(void);")                                                                 
     call append(10," ")                                                                                             
     call append(11, "      ".a:ClassName." &  operator=(".a:ClassName. " const & rhs);")                                                                                             
     call append(12," ")                                                                                             
     call append(13, "   private:")                                                                                       
     call append(14, "};")                                                                                               
     call append(15,"#endif // ".toupper(a:ClassName)."_H")                                                              
     :execute 'write' header                                                                                             
   "================== editing source file ========================                                                      
     let src    = a:ClassName.".cpp"                                                                                     
     :vsp %:h/.cpp                                                                                                                                                                                                                     
     :execute "normal! a#include \"" . a:ClassName . ".hpp\"\<cr>\<cr>"
     call append(1," ")                                                                                                   
     call append(2,a:ClassName."::".a:ClassName."(void){")                                                                           
     call append(3," ")                                                                                                   
     call append(4,"    return ;")                                                                                             
     call append(5,"}")                                                                                                   
     call append(6," ")                                                                                                   
     call append(7,a:ClassName."::".a:ClassName."(".a:ClassName. " const & src){")                                                                           
     call append(8," ")                                                                                                   
     call append(9,"    return ;")                                                                                             
     call append(10,"}")
     call append(11," ")                                                                                                   
     call append(12,a:ClassName."::~".a:ClassName."(void){")                                                                         
     call append(13," ")                                                                                                   
     call append(14,"   return ;")                                                                                            
     call append(15,"}")                                                                                                  
     call append(16," ")                                                                                                   
     call append(17,a:ClassName." & ".a:ClassName."::operator=(".a:ClassName. " const & rhs){")                                                                                             
     call append(18," ")                                                                                                   
     call append(19,"   //this->default = rhs->default;")                                                                                            
     call append(20,"   return *this;")                                                                                            
     call append(21,"}") 
     :execute 'write' src
 endfunction

command! -nargs=1 Cclass call Cclass(<f-args>) 
