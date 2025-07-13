package com.example.dailyroutine;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface TaskTueDAO {
    @Query("select * from Tue_Table")
    List<TaskTue> getAllTasks();

    @Insert
    void insertTask(TaskTue tm);

    @Update
    void updateTask(TaskTue tm);

    @Delete
    void deleteTask(TaskTue tm);

    @Query("delete from Tue_Table")
    void deleteAllTasks();
}
