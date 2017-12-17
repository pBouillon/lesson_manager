/* TABLE: user */
create table if not exists `user` (
    `login`     varchar (150) not null,
    `psswd`     varchar (150) not null,
    `rights`    integer       not null,
    `name`      varchar (150) not null,

    constraint `PK_user` primary key (`login`) 
) ;


 --insert into `user` (`login`, `psswd`, `rights`, `name`)
 --values ("a", "a", 3, "superuser") ;    

 --insert into `user` (`login`, `psswd`, `rights`, `name`)
 --values ("student", "student", 1, "eleve") ;

 --insert into `user` (`login`, `psswd`, `rights`, `name`)
 --values ("teach", "teach", 2, "superuser") ;    

/* TABLE: lesson */
create table if not exists `lesson` (
    `id`        integer       not null   primary key autoincrement ,
    `title`     varchar (150) not null,
    `teacher`   varchar (150) not null,
    `slots`     integer       not null,
    `begin`     integer       not null,
    `end`       integer       not null,
    `published` integer       not null    default 0,

    constraint `FK_teacher` foreign key (`teacher`) references user(`login`)
) ;


/* TABLE: subscriber */
create table if not exists `subscriber` (
    `login`     varchar (150) not null,
    `lesson_id` integer       not null,
    `state`    	integer       not null,
    `order`     integer	      not null,

    constraint `PK_user` 
        primary key (`login`, `lesson_id`),
    constraint `FK_lesson` 
        foreign key (`lesson_id`) 
		references lesson(`id`),
    constraint `FK_user`
        foreign key (`login`) 
		references user(`login`)	
) ;
