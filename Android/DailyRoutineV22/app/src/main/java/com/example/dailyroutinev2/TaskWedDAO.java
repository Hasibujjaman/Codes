package com.example.dailyroutinev2;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface TaskWedDAO {
    @Query("select * from Wed_Table")
    List<TaskWed> getAllTasks();

    @Insert
    void insertTask(TaskWed tm);

    @Update
    void updateTask(TaskWed tm);

    @Delete
    void deleteTask(TaskWed tm);

    @Query("delete from Wed_Table")
    void deleteAllTasks();
}
