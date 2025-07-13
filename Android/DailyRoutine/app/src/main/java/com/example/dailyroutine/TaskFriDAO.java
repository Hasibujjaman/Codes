package com.example.dailyroutine;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface TaskFriDAO {
    @Query("select * from Fri_Table")
    List<TaskFri> getAllTasks();

    @Insert
    void insertTask(TaskFri tm);

    @Update
    void updateTask(TaskFri tm);

    @Delete
    void deleteTask(TaskFri tm);

    @Query("delete from Fri_Table")
    void deleteAllTasks();
}
