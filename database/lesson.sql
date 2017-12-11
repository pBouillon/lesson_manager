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
