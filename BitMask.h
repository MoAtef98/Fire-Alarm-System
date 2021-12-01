

#ifndef BITMASK_H_
#define BITMASK_H_

#define SET_BIT(REG,BIT)           (REG=REG|(1<<BIT))
#define CLR_BIT(REG,BIT)           (REG=REG&(~(1<<BIT)))
#define TOG_BIT(REG,BIT)           (REG=REG^(1<<BIT))
#define READ_BIT(REG,BIT)          ((REG>>BIT)&1)
#define WRITE_BIT(REG,BIT,VALUE)   (REG= ((REG&~(1<<BIT)) | (REG | (VALUE<<BIT))))
#define ASSIGN_REG(REG,VALUE)      (REG=VALUE)

#endif /* BITMASK_H_ */