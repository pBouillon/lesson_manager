/* TABLE: user */
create table if not exists `user` (
    `login`     varchar (150) not null,
    `psswd`     varchar (150) not null,
    `rights`    integer       not null,
    `name`      varchar (150) not null,

    constraint `PK_user` primary key (`login`)
) ;


/* TABLE: lesson */
create table if not exists `lesson` (
    `id`        integer       primary key autoincrement not null ,
    `title`     varchar (150) not null,
    `teacher`   varchar (150) not null,
    `place`     integer       not null,
    `begin`     integer       not null,
    `end`       integer       not null,

    constraint `FK_teacher` foreign key (`teacher`) references user(`login`)
) ;

 --insert into `user` (`login`, `psswd`, `rights`, `name`)
 --values ("a", "a", 3, "superuser") ;    

 --insert into `user` (`login`, `psswd`, `rights`, `name`)
 --values ("random", "student", 1, "eleve") ;

 --insert into `user` (`login`, `psswd`, `rights`, `name`)
 --values ("random", "teach", 2, "superuser") ;    
