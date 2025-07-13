package com.example.dailyroutinev2;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface TaskSunDAO {
    @Query("select * from Sun_Table")
    List<TaskSun> getAllTasks();

    @Insert
    void insertTask(TaskSun tm);

    @Update
    void updateTask(TaskSun tm);

    @Delete
    void deleteTask(TaskSun tm);

    @Query("delete from Sun_Table")
    void deleteAllTasks();
}
