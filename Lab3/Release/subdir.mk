################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Game.cpp \
../Player.cpp \
../cell.cpp \
../main.cpp \
../movesList.cpp 

OBJS += \
./Game.o \
./Player.o \
./cell.o \
./main.o \
./movesList.o 

CPP_DEPS += \
./Game.d \
./Player.d \
./cell.d \
./main.d \
./movesList.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


