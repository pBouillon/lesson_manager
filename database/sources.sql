/* TABLE: user */
create or if not exists table `user` (
    `login`     varchar (150) not null,
    `psswd`     varchar (150) not null,
    `rights`    integer       not null,
    `name`      varchar (150) not null,

    constraint `PK_user` primary key (`login`)
) ;


 --insert into `user` (`login`, `psswd`, `rights`, `name`)
 --values ("a", "a", 3, "superuser") ;    

 --insert into `user` (`login`, `psswd`, `rights`, `name`)
 --values ("random", "student", 1, "eleve") ;

 --insert into `user` (`login`, `psswd`, `rights`, `name`)
 --values ("random", "teach", 2, "superuser") ;    
