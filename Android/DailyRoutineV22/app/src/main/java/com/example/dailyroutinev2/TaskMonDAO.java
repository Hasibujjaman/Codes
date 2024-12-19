package com.example.dailyroutinev2;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface TaskMonDAO {
    @Query("select * from Mon_Table")
    List<TaskMon> getAllTasks();

    @Insert
    void insertTask(TaskMon tm);

    @Update
    void updateTask(TaskMon tm);

    @Delete
    void deleteTask(TaskMon tm);

    @Query("delete from Mon_Table")
    void deleteAllTasks();
}
