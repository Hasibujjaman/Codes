package com.example.dailyroutinev1;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface TaskSatDAO {
    @Query("select * from Sat_Table")
    List<TaskSat> getAllTasks();

    @Insert
    void insertTask(TaskSat tm);

    @Update
    void updateTask(TaskSat tm);

    @Delete
    void deleteTask(TaskSat tm);

    @Query("delete from Sat_Table")
    void deleteAllTasks();

}
