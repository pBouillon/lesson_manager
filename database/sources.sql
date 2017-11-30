/* TABLE: user */
create table if not exists `user` (
    `login`     varchar (150) not null,
    `psswd`     varchar (150) not null,
    `rights`    integer       not null,
    `name`      varchar (150) not null,

    constraint `PK_user` primary key (`login`)
) ;


-- insert into `user` (`login`, `psswd`, `rights`, `name`)
-- values ("a", "a", 3, "superuser") ;    
