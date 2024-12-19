package com.example.dailyroutinev1;

import androidx.room.ColumnInfo;
import androidx.room.Entity;
import androidx.room.Ignore;
import androidx.room.PrimaryKey;

@Entity(tableName = "Thu_Table")
public class TaskThu {
    @PrimaryKey(autoGenerate = false)
    int id;
    @ColumnInfo(name = "Additional_Task")
    String ai;
    @ColumnInfo(name = "Image")
    int img;
    @ColumnInfo(name = "Task")
    String task;
    @ColumnInfo(name = "Time")
    String time;

    public TaskThu(int id, String ai, int img, String task, String time) {
        this.id = id;
        this.ai = ai;
        this.img = img;
        this.task = task;
        this.time = time;
    }
    @Ignore
    public TaskThu(int id, String ai, String task, String time) {
        this.id = id;
        this.ai = ai;
        this.task = task;
        this.time = time;
    }


    @Ignore
    public TaskThu(String ai, String task, String time) {
        this.ai = ai;
        this.task = task;
        this.time = time;
    }
    @Ignore
    public TaskThu(int id){
        this.id = id;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getAI() {
        return ai;
    }

    public void setAI(String ai) {
        this.ai = ai;
    }

    public int getImg() {
        return img;
    }

    public void setImg(int img) {
        this.img = img;
    }

    public String getTask() {
        return task;
    }

    public void setTask(String task) {
        this.task = task;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }
}
