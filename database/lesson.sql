/* TABLE: lesson */
create table if not exists `lesson` (
    /* TODO: primary key as constraint */
    `id`        integer       primary key autoincrement not null ,
    `title`     varchar (150) not null,
    `teacher`   varchar (150) not null,
    `slots`     integer       not null,
    `begin`     integer       not null,
    `end`       integer       not null,

    constraint `FK_teacher` foreign key (`teacher`) references user(`login`)
) ;
