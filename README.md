
# 42 MEMORY MANAGER

Des fonctions à utiliser pour ne plus avoir de problème de memory leak\
&nbsp;\
&nbsp;\
&nbsp;\
Utiliser `memory_manager_2` :\
&nbsp;


#### &nbsp;Fonctions:

&nbsp;&nbsp;`ftm_malloc(size_t sz)`&nbsp;&nbsp;fonction pour malloc()
##
&nbsp;&nbsp;`ftm_free(void *mem)`&nbsp;&nbsp;fonction pour free()
##
&nbsp;&nbsp;`ftm_open(char *pathname, int flags)`&nbsp;&nbsp;fonction pour open()
##
&nbsp;&nbsp;`ftm_close(int fd)`&nbsp;&nbsp;fonction pour close()
##
&nbsp;&nbsp;`ftm_free_all(void)`&nbsp;&nbsp;fonction pour free ou close l'intégralité des malloc ou open non free ou close (à rajouter avant un exit ou un le return final)
##
&nbsp;&nbsp;`ftm_add_track(void *mem)`&nbsp;&nbsp;fonction pour ajouter un adresse allouée dans la liste si elle n'y est pas déjà
##
&nbsp;&nbsp;`ftm_add_track(void *mem)`&nbsp;&nbsp;fonction pour retirer un adresse de la liste
