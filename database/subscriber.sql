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
