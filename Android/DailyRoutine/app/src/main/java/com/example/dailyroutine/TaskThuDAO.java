package com.example.dailyroutine;

import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface TaskThuDAO {
    @Query("select * from Thu_Table")
    List<TaskThu> getAllTasks();

    @Insert
    void insertTask(TaskThu tm);

    @Update
    void updateTask(TaskThu tm);

    @Delete
    void deleteTask(TaskThu tm);

    @Query("delete from Thu_Table")
    void deleteAllTasks();
}
